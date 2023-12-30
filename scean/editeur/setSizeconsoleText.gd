extends RichTextLabel



func _ready():
	self.custom_minimum_size = get_parent().size

func _process(delta):
	if self.custom_minimum_size != Vector2(get_parent().size) :
		self.custom_minimum_size = get_parent().size
