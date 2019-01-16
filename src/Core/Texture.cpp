#include <Core/Texture.h>
#include <qimagereader.h>

Texture::Texture(TextureType textureType) : QObject(0) {
    m_enabled = true;
    m_textureType = textureType;
}

void Texture::loadFromFile(QString filePath) {
    m_filePath = filePath;
    QImageReader reader(m_filePath);
    m_image = reader.read().mirrored();
    if (m_image.isNull()) {
        qWarning() << reader.errorString();
    }
    filePathChanged(m_filePath);
    imageChanged(m_image);
}

void Texture::saveToFile() {
    m_image.save(m_filePath);
}

void Texture::dumpObjectInfo(int l) {
    qDebug().nospace() << tab(l) << "Texture: " << objectName();
    qDebug().nospace() << tab(l + 1) << "Enabled: " << m_enabled;
    qDebug().nospace() << tab(l + 1) << "Type: " <<
        (m_textureType == Diffuse ? "Diffuse" : (m_textureType == Specular ? "Specular" : "Height"));
    qDebug().nospace() << tab(l + 1) << "Filepath: " << m_filePath;
    qDebug().nospace() << tab(l + 1) << "Resolution: " << m_image.width() << "*" << m_image.height();
}

void Texture::dumpObjectTree(int l) {
    dumpObjectInfo(l);
}

bool Texture::enabled() const {
    return m_enabled;
}

Texture::TextureType Texture::textureType() const {
    return m_textureType;
}

QString Texture::filePath() const {
    return m_filePath;
}

const QImage & Texture::image() const {
    return m_image;
}

void Texture::setEnabled(bool enabled) {
    if (m_enabled != enabled) {
        m_enabled = enabled;
        enabledChanged(m_enabled);
    }
}

void Texture::setTextureType(TextureType textureType) {
    if (m_textureType != textureType) {
        m_textureType = textureType;
        textureTypeChanged(m_textureType);
    }
}