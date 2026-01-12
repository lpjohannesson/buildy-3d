extends Control
class_name CursorManager

const RAY_DISTANCE := 1000.0

@export var cursor_point: Node3D

func cast_from_screen(screen_position: Vector2) -> Dictionary:
	var camera := GameScene.instance.camera
	
	var ray_origin := camera.project_ray_origin(screen_position)
	var ray_normal := camera.project_ray_normal(screen_position)
	
	var space_state := camera.get_world_3d().direct_space_state
	var ray_query := PhysicsRayQueryParameters3D.create(
		ray_origin, ray_normal * RAY_DISTANCE)
	
	return space_state.intersect_ray(ray_query)

func _process(delta: float) -> void:
	var screen_cast := cast_from_screen(get_viewport().get_mouse_position())
	
	if screen_cast.is_empty():
		cursor_point.hide()
	else:
		cursor_point.show()
		cursor_point.global_position = screen_cast.position
		cursor_point.quaternion = Quaternion(Vector3.UP, screen_cast.normal)

func _input(event: InputEvent) -> void:
	if not event is InputEventMouseButton:
		return
	
	if not event.is_pressed():
		return
	
	var screen_cast := cast_from_screen(event.position)
	
	if screen_cast.is_empty():
		return
	
	var voxel_position := Vector3i(
		(screen_cast.position - screen_cast.normal * 0.1).floor())
	
	var voxel_manager := GameScene.instance.voxel_manager
	
	match event.button_index:
		MOUSE_BUTTON_LEFT:
			var cell_handle := VoxelCellHandle.new()
			cell_handle.set_shape_index(0)
			
			voxel_manager.set_cell(
				voxel_position,
				cell_handle)
			
			voxel_manager.update_map()
		MOUSE_BUTTON_RIGHT:
			var cell_handle := VoxelCellHandle.new()
			cell_handle.set_shape_index(1)
			cell_handle.set_material_index(GameScene.instance.ui.material_index)
			
			voxel_manager.set_cell(
				voxel_position + Vector3i(screen_cast.normal),
				cell_handle)
			
			voxel_manager.update_map()
