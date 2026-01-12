#pragma once
#include <cstdint>

namespace godot {
	struct VoxelCell {
		std::uint8_t shape_index;
		std::uint8_t material_index;
	};
}