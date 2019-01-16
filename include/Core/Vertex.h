#pragma once

#include <Core/Common.h>

class Vertex {
public:
    Vertex(QVector3D _position = QVector3D(0, 0, 0),
           QVector3D _normal = QVector3D(0, 0, 1),
           QVector3D _tangent = QVector3D(0, 1, 0),
           QVector3D _bitangent = QVector3D(1, 0, 0),
           QVector2D _texCoords = QVector2D(0, 0)) {
        position = _position;
        normal = _normal;
        tangent = _tangent;
        bitangent = _bitangent;
        texCoords = _texCoords;
    }
    Vertex(const Vertex &other) {
        position = other.position;
        normal = other.normal;
        tangent = other.tangent;
        bitangent = other.bitangent;
        texCoords = other.texCoords;
    }
    Vertex& operator=(const Vertex &other) {
        position = other.position;
        normal = other.normal;
        tangent = other.tangent;
        bitangent = other.bitangent;
        texCoords = other.texCoords;
        return *this;
    }
    bool operator==(const Vertex &other) const {
        return position == other.position
            && normal == other.normal
            && tangent == other.tangent
            && bitangent == other.bitangent
            && texCoords == other.texCoords;
    }

    QVector3D position;
    QVector3D normal;
    QVector3D tangent;
    QVector3D bitangent;
    QVector2D texCoords;
};
