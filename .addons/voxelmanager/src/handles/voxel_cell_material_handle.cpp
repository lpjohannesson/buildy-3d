#include "voxel_cell_material_handle.h"
#include <godot_cpp/core/class_db.hpp>

using namespace godot;

void VoxelCellMaterialHandle::_bind_methods() {
	ClassDB::bind_method(D_METHOD("get_material_index"), &VoxelCellMaterialHandle::get_material_index);
	ClassDB::bind_method(D_METHOD("set_material_index", "material_index"), &VoxelCellMaterialHandle::set_material_index);

	ClassDB::bind_method(D_METHOD("get_color_index"), &VoxelCellMaterialHandle::get_color_index);
	ClassDB::bind_method(D_METHOD("set_color_index", "color_index"), &VoxelCellMaterialHandle::set_color_index);
}

std::uint8_t VoxelCellMaterialHandle::get_material_index() const {
  return material.material_index;
}

void VoxelCellMaterialHandle::set_material_index(std::uint8_t material_index) {
	material.material_index = material_index;
}

std::uint8_t VoxelCellMaterialHandle::get_color_index() const {
	return material.color_index;
}

void VoxelCellMaterialHandle::set_color_index(std::uint8_t color_index) {
	material.color_index = color_index;
}

VoxelCellMaterialHandle::VoxelCellMaterialHandle(VoxelCellMaterial material) {
	this->material = material;
}

VoxelCellMaterialHandle::VoxelCellMaterialHandle() {}

VoxelCellMaterialHandle::~VoxelCellMaterialHandle() {}
