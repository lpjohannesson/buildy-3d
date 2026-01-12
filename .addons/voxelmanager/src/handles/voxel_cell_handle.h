#pragma once
#include <godot_cpp/classes/object.hpp>
#include "voxel_cell.h"
#include "voxel_cell_material_handle.h"

namespace godot {
	class VoxelCellHandle : public Object {
		GDCLASS(VoxelCellHandle, Object)

	protected:
		static void _bind_methods();

	public:
		VoxelCell cell;

		std::uint8_t get_shape_index() const;
		void set_shape_index(std::uint8_t shape_index);

		VoxelCellMaterialHandle *get_material() const;
		void set_material(VoxelCellMaterialHandle *material_handle);

		VoxelCellHandle(VoxelCell cell);

		VoxelCellHandle();
		~VoxelCellHandle();
	};
}