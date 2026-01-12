#pragma once
#include <godot_cpp/classes/object.hpp>
#include "voxel_cell_material.h"

namespace godot {
	class VoxelCellMaterialHandle : public Object {
		GDCLASS(VoxelCellMaterialHandle, Object)

	protected:
		static void _bind_methods();

	public:
		VoxelCellMaterial material;

		std::uint8_t get_material_index() const;
		void set_material_index(std::uint8_t material_index);

		std::uint8_t get_color_index() const;
		void set_color_index(std::uint8_t color_index);

		VoxelCellMaterialHandle(VoxelCellMaterial material);

		VoxelCellMaterialHandle();
		~VoxelCellMaterialHandle();
	};
}