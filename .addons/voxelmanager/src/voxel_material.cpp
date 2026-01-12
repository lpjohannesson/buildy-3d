#include "voxel_material.h"

using namespace godot;

void VoxelMaterial::_bind_methods() {
	ClassDB::bind_method(D_METHOD("get_texture"), &VoxelMaterial::get_texture);
	ClassDB::bind_method(D_METHOD("set_texture", "texture"), &VoxelMaterial::set_texture);

	ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "texture", PROPERTY_HINT_RESOURCE_TYPE, "Texture2D"), "set_texture", "get_texture");
}

Ref<Texture2D> VoxelMaterial::get_texture() const {
  return texture;
}

void VoxelMaterial::set_texture(Ref<Texture2D> texture) {
	this->texture = texture;
}

VoxelMaterial::VoxelMaterial() {}

VoxelMaterial::~VoxelMaterial() {}
