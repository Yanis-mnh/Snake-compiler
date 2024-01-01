extends Control

@onready var window:Node = get_parent()
var oldPosition:Vector2i =  DisplayServer.window_get_position(0)

func _ready():
	#size
	self.custom_minimum_size = get_parent().size
	#position
	get_parent().size.x = 400
	

func _process(_delta):
	if(oldPosition != DisplayServer.window_get_position(0)):
		get_parent().position.x = DisplayServer.window_get_position(0).x + DisplayServer.window_get_size(0).x - get_parent().size.x
		get_parent().position.y = DisplayServer.window_get_position(0).y +30
		get_parent().size.y = DisplayServer.window_get_size(0).y -30
		oldPosition = DisplayServer.window_get_position(0)

	if self.custom_minimum_size != Vector2(get_parent().size) :
		self.custom_minimum_size = get_parent().size
		


func _get_console_text()  -> RichTextLabel:
	return $MarginContainer/consoleText


func _on_console_about_to_popup():
	get_parent().position.x = DisplayServer.window_get_position(0).x + DisplayServer.window_get_size(0).x - get_parent().size.x
	get_parent().position.y = DisplayServer.window_get_position(0).y +30
	get_parent().size.y = DisplayServer.window_get_size(0).y -30
	oldPosition = DisplayServer.window_get_position(0)
