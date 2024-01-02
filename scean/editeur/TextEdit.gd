extends TextEdit




func _ready():
	
	
	#set the color theme for the text editor (text)
	var highlighter := CodeHighlighter.new()
	const KEYWORD:Array = [
		"Snk_Begin",
		"Snk_Int",
		"Snk_Real",
		"Begin",
		"Set",
		"If",
		"Else",
		"Get",
		"Snk_Print",
		"Snk_End"]
	highlighter.number_color = "#ffe085"
	highlighter.symbol_color = "#4c6c80"
	highlighter.member_variable_color = "#2ea781"
	for kw in KEYWORD:
		highlighter.add_keyword_color(kw, Color("#92C7CF"))
	
		
	highlighter.add_color_region("$$","",Color("#6e6e6e"),true);
	highlighter.add_color_region("\"","\"",Color("#ffe085"),false);
	syntax_highlighter = highlighter




