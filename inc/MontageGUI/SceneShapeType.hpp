#ifndef MONTAGE_SCENE_SHAPE_TYPE
#define MONTAGE_SCENE_SHAPE_TYPE

namespace MontageGUI {

enum class SceneShapeType {
    NOTHING,
    RECTANGLE,
    ELLIPSE,
    _SIZE,
};

SceneShapeType &operator++(SceneShapeType &state);

} // namespace MontageGUI

#endif
