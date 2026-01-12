extends CanvasLayer
class_name UI

@export var material_container: Control
@export var color_container: Control

@export var material_button_scene: PackedScene
@export var color_button_scene: PackedScene

var selected_material := VoxelCellMaterialHandle.new()

func _ready() -> void:
	selected_material.set_material_index(0)
	selected_material.set_color_index(0)
	
	(func():
		var voxel_manager := GameScene.instance.voxel_manager
		
		for i in range(voxel_manager.materials.size()):
			var material := voxel_manager.materials[i]
			
			var button: TextureButton = material_button_scene.instantiate()
			material_container.add_child(button)
			
			button.pressed.connect(func():
				selected_material.set_material_index(i))
			
			button.texture_normal = material.texture
		
		for i in range(voxel_manager.material_colors.size()):
			var color := voxel_manager.material_colors[i]
			
			var button: Button = color_button_scene.instantiate()
			color_container.add_child(button)
			
			button.pressed.connect(func():
				selected_material.set_color_index(i))
			
			var button_style := StyleBoxFlat.new()
			button_style.bg_color = color
			
			button.add_theme_stylebox_override("normal", button_style)
			button.add_theme_stylebox_override("hover", button_style)
			button.add_theme_stylebox_override("pressed", button_style)
	).call_deferred()
