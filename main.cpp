#include <QApplication>
#include <QMainWindow>
#include <QPainter>
#include <QTimer>

class EllipseWindow : public QMainWindow
{
public:
    EllipseWindow(QWidget *parent = nullptr) : QMainWindow(parent)
    {
        resize(800, 600);
        setWindowTitle("Moving Ellipse");
        
        timer = new QTimer(this);
        connect(timer, &QTimer::timeout, this, &EllipseWindow::updateEllipse);
        timer->start(50);
    }

protected:
    void paintEvent(QPaintEvent *event) override
    {
        Q_UNUSED(event);
        
        QPainter painter(this);
        painter.setRenderHint(QPainter::Antialiasing);

        painter.setBrush(Qt::red);
        painter.drawEllipse(ellipseRect);
    }
    
    void updateEllipse()
    {
        ellipseRect.moveLeft(ellipseRect.left() + 5);

        if (ellipseRect.left() > width())
        {
            ellipseRect.moveLeft(-ellipseRect.width());
        }

        update();
    }

private:
    QRect ellipseRect = QRect(0, 200, 100, 100);
    QTimer *timer;
};

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    EllipseWindow window;
    window.show();

    return app.exec();
}
