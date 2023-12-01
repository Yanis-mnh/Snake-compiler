extends MenuBar

@onready var big_small = $HBoxContainer/big_small

func _ready():
	pass

func _on_close_pressed():
	get_tree().quit()

func _on_big_small_pressed():
	if(DisplayServer.window_get_mode() != DisplayServer.WINDOW_MODE_FULLSCREEN):
		DisplayServer.window_set_mode(DisplayServer.WINDOW_MODE_FULLSCREEN)
		big_small.icon = preload("res://assets/icons/restore-down.png")
		return
	DisplayServer.window_set_mode(DisplayServer.WINDOW_MODE_WINDOWED)
	big_small.icon = preload("res://assets/icons/maximize.png")

func _on_minimaze_pressed():
	DisplayServer.window_set_mode(DisplayServer.WINDOW_MODE_MINIMIZED)
