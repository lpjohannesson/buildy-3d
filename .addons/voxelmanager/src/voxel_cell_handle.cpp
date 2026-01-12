#include "voxel_cell_handle.h"
#include <godot_cpp/core/class_db.hpp>

using namespace godot;

void VoxelCellHandle::_bind_methods() {
	ClassDB::bind_method(D_METHOD("get_shape_index"), &VoxelCellHandle::get_shape_index);
	ClassDB::bind_method(D_METHOD("set_shape_index", "shape_index"), &VoxelCellHandle::set_shape_index);

	ClassDB::bind_method(D_METHOD("get_material_index"), &VoxelCellHandle::get_material_index);
	ClassDB::bind_method(D_METHOD("set_material_index", "material_index"), &VoxelCellHandle::set_material_index);
}

std::uint8_t VoxelCellHandle::get_shape_index() const {
	return cell.shape_index;
}

void VoxelCellHandle::set_shape_index(std::uint8_t shape_index) {
	cell.shape_index = shape_index;
}

std::uint8_t VoxelCellHandle::get_material_index() const {
	return cell.material_index;
}

void VoxelCellHandle::set_material_index(std::uint8_t material_index) {
	cell.material_index = material_index;
}

VoxelCellHandle::VoxelCellHandle(VoxelCell cell) {
	this->cell = cell;
}

VoxelCellHandle::VoxelCellHandle() {}

VoxelCellHandle::~VoxelCellHandle() {}
