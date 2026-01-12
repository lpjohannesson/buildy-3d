#include "voxel_manager.h"
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/classes/csg_box3d.hpp>
#include <godot_cpp/classes/concave_polygon_shape3d.hpp>

using namespace godot;

void VoxelManager::_bind_methods() {
	ClassDB::bind_method(D_METHOD("get_cell", "voxel_position"), &VoxelManager::get_cell);
	ClassDB::bind_method(D_METHOD("set_cell", "voxel_position", "cell_handle"), &VoxelManager::set_cell);
	
	ClassDB::bind_method(D_METHOD("update_map"), &VoxelManager::update_map);
	ClassDB::bind_method(D_METHOD("bake_map"), &VoxelManager::bake_map);

	ClassDB::bind_method(D_METHOD("get_materials"), &VoxelManager::get_materials);
	ClassDB::bind_method(D_METHOD("set_materials", "materials"), &VoxelManager::set_materials);
	ADD_PROPERTY(PropertyInfo(
        Variant::ARRAY, 
        "materials", 
        PROPERTY_HINT_TYPE_STRING, 
        vformat("%d/%d:%s", Variant::OBJECT, PROPERTY_HINT_RESOURCE_TYPE, "VoxelMaterial")
    ), "set_materials", "get_materials");

	ClassDB::bind_method(D_METHOD("get_material_colors"), &VoxelManager::get_material_colors);
	ClassDB::bind_method(D_METHOD("set_material_colors", "material_colors"), &VoxelManager::set_material_colors);
	ADD_PROPERTY(PropertyInfo(Variant::PACKED_COLOR_ARRAY, "material_colors"), "set_material_colors", "get_material_colors");
}

VoxelCellHandle *VoxelManager::get_cell(Vector3i voxel_position) const {
	return memnew(VoxelCellHandle(cells[voxel_position.x][voxel_position.y][voxel_position.z]));
}

void VoxelManager::set_cell(Vector3i voxel_position, VoxelCellHandle *cell_handle) {
	cells[voxel_position.x][voxel_position.y][voxel_position.z] = cell_handle->cell;
}

TypedArray<Ref<VoxelMaterial>> VoxelManager::get_materials() const {
	return materials;
}

void VoxelManager::set_materials(const TypedArray<Ref<VoxelMaterial>> &materials) {
	this->materials = materials;
}

PackedColorArray VoxelManager::get_material_colors() const {
	return material_colors;
}

void VoxelManager::set_material_colors(const PackedColorArray &material_colors) {
	this->material_colors = material_colors;
}

void VoxelManager::update_map() {
	for (int x = 0; x < MAP_WIDTH; x++) {
		for (int y = 0; y < MAP_HEIGHT; y++) {
			for (int z = 0; z < MAP_DEPTH; z++) {
				const VoxelCell& cell = cells[x][y][z];

				if (cell.shape_index == 0) {
					continue;
				}

				CSGBox3D* csg_box = memnew(CSGBox3D);
				csg_combiner->add_child(csg_box);

				csg_box->set_position(Vector3(x, y, z) + Vector3(0.5, 0.5, 0.5));

				Ref<StandardMaterial3D> mesh_material = mesh_material_sets[cell.material.material_index][cell.material.color_index];
				csg_box->set_material(mesh_material);
			}
		}
	}

	call_deferred("bake_map");
}

void VoxelManager::bake_map() {
	mesh->set_mesh(csg_combiner->bake_static_mesh());
	shape->set_shape(csg_combiner->bake_collision_shape());
	
	for (Variant &child : csg_combiner->get_children()) {
		((Node&)child).queue_free();
	}
}

void VoxelManager::_ready() {
	csg_combiner = memnew(CSGCombiner3D);
	add_child(csg_combiner);

	mesh = memnew(MeshInstance3D);
	add_child(mesh);

	body = memnew(StaticBody3D);
	add_child(body);

	shape = memnew(CollisionShape3D);
	body->add_child(shape);

	for (const Ref<VoxelMaterial> &material : materials) {
		const Ref<Texture2D> &texture = material->texture;

		mesh_material_sets.push_back({});
		auto &mesh_material_set = mesh_material_sets.back();

		for (int i = 0; i < material_colors.size(); i++) {
			Ref<StandardMaterial3D> mesh_material = memnew(StandardMaterial3D);
			
			mesh_material->set_texture(BaseMaterial3D::TEXTURE_ALBEDO, texture);
			mesh_material->set_albedo(material_colors[i]);

			mesh_material_set[i] = mesh_material;
		}
	}
}

VoxelManager::VoxelManager() {}

VoxelManager::~VoxelManager() {}
