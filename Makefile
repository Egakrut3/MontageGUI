LINKER_FIXED_OPTIONS	+=	-lsfml-graphics -lsfml-window -lsfml-system

MONTAGE_GUI_DIR			=	MontageGUI/
MONTAGE_GUI_FILES		=	WindowBase SceneShape SceneRectangle SceneEllipse Scene SceneShapeType Application
INC						=	$(addprefix $(MONTAGE_GUI_DIR),$(MONTAGE_GUI_FILES))
SRC						=	main $(addprefix $(MONTAGE_GUI_DIR),$(MONTAGE_GUI_FILES))

RUN_TARGET				=	prime-run taskset -c 14 ./$(TARGET)



COMMON_MAKEFILE = Common_Makefile.mk
include $(COMMON_MAKEFILE)



prepare::
	@mkdir -p $(addprefix $(DEP_SUBDIR),$(MONTAGE_GUI_DIR)) $(addprefix $(BIN_SUBDIR),$(MONTAGE_GUI_DIR))
