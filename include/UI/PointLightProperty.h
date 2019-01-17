#pragma once

#include <UI/Common.h>
#include <UI/Vector3DEditSlider.h>

class PointLightProperty: public QWidget {
    Q_OBJECT

public:
    PointLightProperty(PointLight * light, QWidget * parent = 0);
    // TODO: Copy constructor

private:
    PointLight *m_host;
    QCheckBox *m_enabledCheckBox;
    QLabel *m_intensityLabel;
    FloatEdit *m_intensityEdit;
    FloatSlider *m_intensitySlider;
    Vector3DEditSlider *m_colorEditSlider;
    Vector3DEdit *m_positionEdit, *m_attenuationEdit;

    void configLayout();
    void configSignals();

private slots:
    // TODO: Connect to host's destroyed signal, commit suicide when host is destroyed.
};