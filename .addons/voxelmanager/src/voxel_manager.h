#pragma once
#include <godot_cpp/classes/node3d.hpp>
#include <godot_cpp/classes/csg_combiner3d.hpp>
#include <godot_cpp/classes/mesh_instance3d.hpp>
#include <godot_cpp/classes/static_body3d.hpp>
#include <godot_cpp/classes/collision_shape3d.hpp>
#include <godot_cpp/classes/standard_material3d.hpp>
#include "voxel_cell_handle.h"

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

			TypedArray<Ref<StandardMaterial3D>> materials;

			VoxelCellHandle *get_cell(Vector3i voxel_position) const;
			void set_cell(Vector3i voxel_position, VoxelCellHandle *cell_handle);

			TypedArray<Ref<StandardMaterial3D>> get_materials() const;
			void set_materials(const TypedArray<Ref<StandardMaterial3D>> &materials);

			void update_map();
			void bake_map();

			void _ready() override;

			VoxelManager();
			~VoxelManager();
	};
}