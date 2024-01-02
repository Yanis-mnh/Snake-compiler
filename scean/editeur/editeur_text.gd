extends Control

enum file_option{
	new_file,
	load_file,
 	save_file,
	save_as_file,
	quit
	}
enum analysuer{
	anal_lex,
	anal_syn,
	anal_sem
	}

@onready var dropMenuFile = $"title bar/MenuBar/HBoxContainer/MenuButton"
@onready var open_file_window = $OpenFileWindow
@onready var save_file_window = $SaveFileWindow
@onready var menu_button_analyse = $"title bar/MenuBar/HBoxContainer/MenuButtonAnalyse"
@onready var text_edit = $TextEdit
@onready var title = $"title bar/title"
@onready var console = $Console
@onready var console_text = $Console/Control._get_console_text()
@onready var confirmation_dialog = $ConfirmationDialog


var oldText:String = ""
var app_name:String = "snake"
var current_file:String = "Untitled"


func _ready():
	DisplayServer.window_set_min_size(Vector2i(791, 641),0)
	get_tree().set_auto_accept_quit(false)
	update_window_name()
	dropMenuFile.get_popup().connect("id_pressed",on_item_pressed)
	menu_button_analyse.get_popup().connect("id_pressed",on_analyse)


#to show the confirmation message when tryin to exite the app
func _notification(what):
	if what == NOTIFICATION_WM_CLOSE_REQUEST:
		_exit_game()




func update_window_name():
	DisplayServer.window_set_title(app_name +" _ "+ current_file)


#les option de l'analyseur 
func on_analyse(id):
	console.hide()
	save_file()
	if(current_file == "Untitled"):
		return
	match id:
		analysuer.anal_lex:
			var exePath = "analyseur/analyse lex/analysuer_lex.exe"
			var arg = [current_file]
			var out_put=[]
			var pid = OS.execute(exePath,PackedStringArray(arg),out_put,false,false)
			print(pid)
			var result:String = array_to_string(out_put)
			console_text.text = result
			OS.kill(pid);
			console.popup()
		analysuer.anal_syn:
			var result:String = "work in progress return later"
			console_text.text = result
			console.popup()
		analysuer.anal_sem:
			var result:String = "work in progress return later"
			console_text.text = result
			console.popup()

#function de getion des button fichier
func on_item_pressed(id):
	console.hide()
	var item_id = dropMenuFile.get_popup().get_item_id(id)
	match item_id:
		file_option.new_file:
			oldText = ""
			current_file = "Untitled"
			text_edit.text = "";
			app_name = "snake"
		file_option.load_file:
			open_file_window.popup_centered()
		file_option.save_file:
			save_file()
		file_option.save_as_file:
			save_file_window.popup_centered()
		file_option.quit:
			_exit_game()


func _on_open_file_window_file_selected(path):
	var file = FileAccess.open(path, FileAccess.READ)
	text_edit.text = file.get_as_text()
	oldText = text_edit.text
	file.close()
	current_file = path
	update_window_name()


func _on_save_file_window_file_selected(path):
	var file = FileAccess.open(path, FileAccess.WRITE)
	file.store_string(text_edit.text)
	file.close()
	current_file = path
	update_window_name()

func save_file():
	var path = current_file
	if path == "Untitled":
		save_file_window.popup_centered()
		return
	var file = FileAccess.open(path, FileAccess.WRITE)
	file.store_string(text_edit.text)
	file.close()
	app_name = "snake"
	update_window_name()


func _on_text_edit_text_changed():
	
	if text_edit.text ==  oldText:
		app_name = "snake"
		update_window_name()
		return
	app_name = "(*) snake"
	update_window_name()



func array_to_string(arr: Array) -> String:
	var s = ""
	for i in arr:
		s += String(i)
	return s


func _on_console_close_requested():
	console.hide()

#short-cut like
func _on_console_window_input(event):
	if event is InputEventKey:
		if event.pressed:
			console.hide()

#exit logique
func _on_confirmation_dialog_confirmed():
	get_tree().queue_delete(self)
	get_tree().quit()

func _exit_game():
	if app_name == "(*) snake":
		confirmation_dialog.popup_centered()
	else:
		get_tree().queue_delete(self)
		get_tree().quit()





func _on_confirmation_dialog_canceled():
	$ConfirmationDialog.hide()

