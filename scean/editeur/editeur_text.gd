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

var app_name = "snake"
var current_file = "Untitled"



func _ready():
	update_window_name()
	dropMenuFile.get_popup().connect("id_pressed",on_item_pressed)
	menu_button_analyse.get_popup().connect("id_pressed",on_analyse)


func update_window_name():
	DisplayServer.window_set_title(app_name +" _ "+ current_file)


#les option de l'analyseur 
func on_analyse(id):
	save_file()
	if(current_file == "Untitled"):
		return
	match id:
		analysuer.anal_lex:
			var exePath = "analyseur/analyse lex/analysuer_lex.exe"
			var arg = [current_file]
			var out_put=[]
			var pid = OS.execute(exePath,PackedStringArray(arg),out_put,false,true)
			print(out_put)
			OS.kill(pid);
		analysuer.anal_syn:
			print("analyse syntaxique")
		analysuer.anal_sem:
			print("analyse semantique")

#function de getion des button fichier
func on_item_pressed(id):
	var item_id = dropMenuFile.get_popup().get_item_id(id)
	match item_id:
		file_option.new_file:
			current_file = "Untitled"
			text_edit.text = "";
		file_option.load_file:
			open_file_window.popup_centered()
		file_option.save_file:
			save_file()
		file_option.save_as_file:
			save_file_window.popup_centered()
		file_option.quit:
			get_tree().quit()


func _on_open_file_window_file_selected(path):
	var file = FileAccess.open(path, FileAccess.READ)
	$TextEdit.text = file.get_as_text();
	file.close()
	current_file = path
	update_window_name()


func _on_save_file_window_file_selected(path):
	var file = FileAccess.open(path, FileAccess.WRITE)
	file.store_string($TextEdit.text)
	file.close()
	current_file = path
	update_window_name()

func save_file():
	var path = current_file
	if path == "Untitled":
		save_file_window.popup_centered()
		return
	var file = FileAccess.open(path, FileAccess.WRITE)
	file.store_string($TextEdit.text)
	file.close()
	app_name = "snake"
	update_window_name()


func _on_text_edit_text_changed():
	app_name = "(*) snake"
	update_window_name()

