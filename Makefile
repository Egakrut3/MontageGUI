LINKER_FIXED_OPTIONS	+=	-lsfml-graphics -lsfml-window -lsfml-system

MONTAGE_GUI_INC			=	Button SceneShape SceneRectangle SceneEllipse Scene SceneShapeType Application
INC						=	$(addprefix MontageGUI/,$(MONTAGE_GUI_INC))

MONTAGE_GUI_SRC			=	Button SceneShape SceneRectangle SceneEllipse Scene SceneShapeType Application
SRC						=	main $(addprefix MontageGUI/,$(MONTAGE_GUI_SRC))

RUN_TARGET				=	prime-run taskset -c 14 ./$(TARGET)



COMMON_MAKEFILE = Common_Makefile.mk
include $(COMMON_MAKEFILE)



prepare::
	@mkdir -p $(addprefix $(DEP_SUBDIR),MontageGUI/) $(addprefix $(BIN_SUBDIR),MontageGUI/)
