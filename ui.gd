extends CanvasLayer
class_name UI

@export var material_container: Control
@export var material_button_scene: PackedScene

var selected_material_index := 0

func _ready() -> void:
	(func():
		var voxel_manager := GameScene.instance.voxel_manager
		
		for i in range(voxel_manager.materials.size()):
			var material := voxel_manager.materials[i]
			
			var button: TextureButton = material_button_scene.instantiate()
			material_container.add_child(button)
			
			button.pressed.connect(func():
				selected_material_index = i)
			
			button.texture_normal = material.albedo_texture
	).call_deferred()
