#include <QScreen>
#include <QScreenDriverPlugin>

QT_BEGIN_NAMESPACE

class Q_GUI_EXPORT QNullScreen : public QScreen
{
public:
	explicit QNullScreen(int displayId) :
		QScreen(displayId, CustomClass)
	{
	}

	virtual bool initDevice()
	{
		return true;
	}

	virtual bool connect(const QString &displaySpec)
	{
		Q_UNUSED(displaySpec)
		return true;
	}

	virtual void disconnect()
	{
	}

	virtual void setMode(int width, int height, int depth)
	{
		Q_UNUSED(width)
		Q_UNUSED(height)
		Q_UNUSED(depth)
	}
};

class QScreenNullPlugin : public QScreenDriverPlugin
{
	static const QStringList nullKeys;
public:
	QStringList keys() const
	{
		return nullKeys;
	}

	QScreen *create(const QString &driver, int displayId)
	{
		return (driver.toLower() == nullKeys.at(0)) ? new QNullScreen(displayId) : 0;
	}
};

const QStringList QScreenNullPlugin::nullKeys("null");

Q_EXPORT_PLUGIN2(qscreennull, QScreenNullPlugin)

QT_END_NAMESPACE
