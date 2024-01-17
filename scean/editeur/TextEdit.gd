extends TextEdit




func _ready():
	
	
	#set the color theme for the text editor (text)
	var highlighter := CodeHighlighter.new()
	const KEYWORD:Array = [
		"Snk_Begin",
		"Begin",
		"Set",
		"If",
		"Else",
		"Get",
		"Snk_Print",
		"Snk_End",
		"While",
		"End",
		"Add",
		"Sub",
		"Mul",
		"Div",
		"from"]
	const Dec:Array =[
		"Snk_Int",
		"Snk_Real"]
	highlighter.number_color = "#ffe085"
	highlighter.symbol_color = "#4c6c80"
	highlighter.member_variable_color = "#2ea781"
	#CC596A :mohamed
	#7590b6 :blue
	
	for kw in KEYWORD:
		highlighter.add_keyword_color(kw, Color("#7590b6"))
	for r in Dec:
		highlighter.add_keyword_color(r, Color("#CC596A"))
	#the comments color one line and muliti-line
	highlighter.add_color_region(";",";",Color("#FE7A36"),false);
	highlighter.add_color_region("$$","",Color("#6e6e6e"),true);
	highlighter.add_color_region("#","#",Color("#6e6e6e"),false);
	
	#color for String type character
	highlighter.add_color_region("\"","\"",Color("#ffe085"),false);
	syntax_highlighter = highlighter




