#include "texture_render_widget.h"

#include <QPainter>

TextureRenderWidget::TextureRenderWidget(int width, int height, QImage::Format imageFormat, QWidget * parent)
    : QOpenGLWidget(parent)
    , renderTexture(new QImage(width, height, imageFormat))
    , textureXOffset(0)
    , textureYOffset(0)
    , textureResolutionMultiplier(3) {}

TextureRenderWidget::~TextureRenderWidget() {
    delete renderTexture;
}

uchar * TextureRenderWidget::getTextureBits() {
    return renderTexture->bits();
}

QSize TextureRenderWidget::sizeHint() const {
    return QSize(renderTexture->width(), renderTexture->height());
}

void TextureRenderWidget::initializeGL() {}

void TextureRenderWidget::paintGL() {
    QPainter p(this);
    p.drawImage(
        textureXOffset,
        textureYOffset,
        renderTexture->scaled(
            QSize(renderTexture->width() * textureResolutionMultiplier,
                  renderTexture->height() * textureResolutionMultiplier))
    );

    update();
}

void TextureRenderWidget::resizeGL(int width, int height) {
    int widthDiv = width / renderTexture->width();
    int heightDiv = height / renderTexture->height();

    textureResolutionMultiplier = widthDiv > heightDiv ? heightDiv : widthDiv;
    if (textureResolutionMultiplier <= 0) textureResolutionMultiplier = 1;

    textureXOffset = width / 2 - renderTexture->width() * textureResolutionMultiplier / 2;
    textureYOffset = height / 2 - renderTexture->height() * textureResolutionMultiplier / 2;
}
