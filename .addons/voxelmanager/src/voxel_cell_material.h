#pragma once
#include <cstdint>

namespace godot {
	struct VoxelCellMaterial {
		std::uint8_t material_index;
		std::uint8_t color_index;
	};
}