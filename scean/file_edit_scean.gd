extends Node2D


# Called when the node enters the scene tree for the first time.
func _ready():
	var array = ["c:\\temp\\test.txt"]
	var args = PackedStringArray(array)
	OS.execute("C:\\Windows\\System32\\notepad.exe",args)


# Called every frame. 'delta' is the elapsed time since the previous frame.
func _process(delta):
	pass
