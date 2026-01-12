#pragma once
#include <cstdint>
#include "voxel_cell_material.h"

namespace godot {
	struct VoxelCell {
		std::uint8_t shape_index;
		VoxelCellMaterial material;
	};
}