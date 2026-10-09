LINKER_FIXED_OPTIONS	+=	-lsfml-graphics -lsfml-window -lsfml-system

MONTAGE_GUI_INC			=	Common Scene Application
INC						=	$(addprefix MontageGUI/,$(MONTAGE_GUI_INC))

MONTAGE_GUI_SRC			=	Common Scene Application
SRC						=	main $(addprefix MontageGUI/,$(MONTAGE_GUI_SRC))

RUN_TARGET				=	prime-run taskset -c 14 ./$(TARGET)



COMMON_MAKEFILE = Common_Makefile.mk
include $(COMMON_MAKEFILE)



prepare::
	@mkdir -p $(addprefix $(DEP_SUBDIR),MontageGUI/) $(addprefix $(BIN_SUBDIR),MontageGUI/)
