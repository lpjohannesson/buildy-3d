#pragma once
#include <godot_cpp/classes/resource.hpp>
#include <godot_cpp/classes/texture2d.hpp>

namespace godot {
	class VoxelMaterial : public Resource {
		GDCLASS(VoxelMaterial, Resource)

	protected:
		static void _bind_methods();

	public:
		Ref<Texture2D> texture;

		Ref<Texture2D> get_texture() const;
		void set_texture(Ref<Texture2D> texture);

		VoxelMaterial();
		~VoxelMaterial();
	};
}