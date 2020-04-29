#ifndef TRTLE_QT_TEXTURE_RENDER_WIDGET_H
#define TRTLE_QT_TEXTURE_RENDER_WIDGET_H

#include <QOpenGLWidget>
#include <QImage>
#include <QOpenGLFunctions>
#include <QSize>

class TextureRenderWidget : public QOpenGLWidget {
public:
    TextureRenderWidget(int textureWidth, int textureHeight, QImage::Format imageFormat, QWidget * parent = nullptr);
    ~TextureRenderWidget();

    uchar * getTextureBits();

protected:
    QSize sizeHint() const override;

    void initializeGL() override;
    void paintGL() override;
    void resizeGL(int width, int height) override;

private:
    QImage * const renderTexture;
    int textureXOffset;
    int textureYOffset;
    int textureResolutionMultiplier;
};

#endif /* !TRTLE_QT_TEXTURE_RENDER_WIDGET_H */
