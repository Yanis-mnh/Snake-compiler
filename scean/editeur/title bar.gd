extends Control

var canMove = false
var init_pos
var isMoving = false

func _process(_delta):
	if Input.is_action_just_pressed("LMB") && canMove == true:
		init_pos = get_local_mouse_position()
		isMoving = true
	if Input.is_action_just_released("LMB"):
		isMoving = false
	if isMoving == true:
		DisplayServer.window_set_position( DisplayServer.window_get_position() + Vector2i(get_global_mouse_position() -init_pos ))


func _on_mouse_entered():
	canMove = true

func _on_mouse_exited():
	canMove = false
