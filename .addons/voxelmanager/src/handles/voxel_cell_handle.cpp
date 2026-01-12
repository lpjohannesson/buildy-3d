#include "voxel_cell_handle.h"
#include <godot_cpp/core/class_db.hpp>

using namespace godot;

void VoxelCellHandle::_bind_methods() {
	ClassDB::bind_method(D_METHOD("get_shape_index"), &VoxelCellHandle::get_shape_index);
	ClassDB::bind_method(D_METHOD("set_shape_index", "shape_index"), &VoxelCellHandle::set_shape_index);

	ClassDB::bind_method(D_METHOD("get_material"), &VoxelCellHandle::get_material);
	ClassDB::bind_method(D_METHOD("set_material", "material_handle"), &VoxelCellHandle::set_material);
}

std::uint8_t VoxelCellHandle::get_shape_index() const {
	return cell.shape_index;
}

void VoxelCellHandle::set_shape_index(std::uint8_t shape_index) {
	cell.shape_index = shape_index;
}

VoxelCellMaterialHandle *VoxelCellHandle::get_material() const {
	return memnew(VoxelCellMaterialHandle(cell.material));
}

void VoxelCellHandle::set_material(VoxelCellMaterialHandle *material_handle) {
	cell.material = material_handle->material;
}

VoxelCellHandle::VoxelCellHandle(VoxelCell cell) {
	this->cell = cell;
}

VoxelCellHandle::VoxelCellHandle() {}

VoxelCellHandle::~VoxelCellHandle() {}
