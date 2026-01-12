#pragma once
#include <godot_cpp/classes/node3d.hpp>
#include <godot_cpp/classes/csg_combiner3d.hpp>
#include <godot_cpp/classes/mesh_instance3d.hpp>
#include <godot_cpp/classes/static_body3d.hpp>
#include <godot_cpp/classes/collision_shape3d.hpp>
#include <godot_cpp/classes/standard_material3d.hpp>
#include "handles/voxel_cell_handle.h"
#include "voxel_material.h"
#include <vector>
#include <array>

namespace godot {
	class VoxelManager : public Node3D {
		GDCLASS(VoxelManager, Node3D)

		protected:
			static void _bind_methods();

		public:
			static constexpr int MAP_WIDTH = 16, MAP_HEIGHT = 16, MAP_DEPTH = 16;
			VoxelCell cells[MAP_WIDTH][MAP_HEIGHT][MAP_DEPTH]{};

			CSGCombiner3D *csg_combiner;
			MeshInstance3D *mesh;
			StaticBody3D *body;
			CollisionShape3D *shape;

			TypedArray<Ref<VoxelMaterial>> materials;
			PackedColorArray material_colors;

			std::vector<std::array<Ref<StandardMaterial3D>, 16>> mesh_material_sets;

			VoxelCellHandle *get_cell(Vector3i voxel_position) const;
			void set_cell(Vector3i voxel_position, VoxelCellHandle *cell_handle);

			TypedArray<Ref<VoxelMaterial>> get_materials() const;
			void set_materials(const TypedArray<Ref<VoxelMaterial>> &materials);

			PackedColorArray get_material_colors() const;
			void set_material_colors(const PackedColorArray &material_colors);

			void update_map();
			void bake_map();

			void _ready() override;

			VoxelManager();
			~VoxelManager();
	};
}