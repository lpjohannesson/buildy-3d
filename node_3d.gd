extends Node3D
class_name GameScene

@export var voxel_manager: VoxelManager
@export var ui: UI
@export var camera: Camera3D

static var instance: GameScene

func _ready() -> void:
	instance = self
	var cell_handle := VoxelCellHandle.new()
	
	cell_handle.set_shape_index(1)
	cell_handle.set_material_index(0)
	
	for x in range(16):
		for z in range(16):
			voxel_manager.set_cell(Vector3i(x, 0, z), cell_handle)
	
	voxel_manager.update_map()
