#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QFileDialog>
#include <QLabel>
#include <opencv2/opencv.hpp>

class ImageProcessor : public QWidget {
    Q_OBJECT

private:
    cv::Mat image;
    QLabel* imageLabel;

public:
    ImageProcessor(QWidget* parent = nullptr) : QWidget(parent) {
        QVBoxLayout* layout = new QVBoxLayout(this);

        QPushButton* loadButton = new QPushButton("Load Image", this);
        connect(loadButton, &QPushButton::clicked, this, &ImageProcessor::loadImage);
        layout->addWidget(loadButton);

        imageLabel = new QLabel(this);
        layout->addWidget(imageLabel);

        setLayout(layout);
    }

private slots:
    void loadImage() {
        QString fileName = QFileDialog::getOpenFileName(this, "Open Image", "", "Image Files (*.png *.jpg *.bmp)");
        if (!fileName.isEmpty()) {
            image = cv::imread(fileName.toStdString());
            displayImage();
        }
    }

    void displayImage() {
        if (!image.empty()) {
            cv::Mat rgbImage;
            cv::cvtColor(image, rgbImage, cv::COLOR_BGR2RGB);
            QImage qImage(rgbImage.data, rgbImage.cols, rgbImage.rows, rgbImage.step, QImage::Format_RGB888);
            imageLabel->setPixmap(QPixmap::fromImage(qImage));
            imageLabel->resize(imageLabel->pixmap()->size());
        }
    }

    // Add functions for image processing operations like filters, color adjustment, crop, resize, etc.
};

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);
    ImageProcessor imageProcessor;
    imageProcessor.show();
    return app.exec();
}

#include "main.moc" // Required for Qt Meta-Object Compiler (MOC)

