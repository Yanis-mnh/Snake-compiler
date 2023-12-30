extends TextEdit




func _ready():
	self.custom_minimum_size.x = DisplayServer.window_get_size().x*0.75;
	self.custom_minimum_size.y = DisplayServer.window_get_size().y;
	
	#set the color theme for the text editor (text)
	var highlighter := CodeHighlighter.new()
	var container:Array = ["Snk_End","Snk_Begin"]
	var declaration:Array = ["Snk_Real","Snk_Int"]
	
	for c in container:
		highlighter.add_keyword_color(c, Color("#FFF5C2"))
	for d in declaration:
		highlighter.add_keyword_color(d, Color("#DF826C"))
	highlighter.add_color_region("$$","",Color("#A9A9A9"),true);
	syntax_highlighter = highlighter




