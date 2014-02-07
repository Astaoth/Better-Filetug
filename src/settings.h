#ifndef SETTINGS_H
#define SETTINGS_H

#include <QObject>
#include <QString>
#include <QDebug>
#include <QSettings>
#include <QDir>

class Settings : public QObject
{
    Q_OBJECT

    // Directory view
    Q_PROPERTY(QString dirPath READ getDirPath WRITE setDirPath NOTIFY dirPathChanged)
    Q_PROPERTY(QString defaultViewMode READ getDefaultViewMode WRITE setDefaultViewMode NOTIFY defaultViewModeChanged)
    Q_PROPERTY(bool showHiddenFiles READ getShowHiddenFiles WRITE setShowHiddenFiles NOTIFY showHiddenFilesChanged)
    Q_PROPERTY(bool showDirHeader READ getShowDirHeader WRITE setShowDirHeader NOTIFY showDirHeaderChanged)
    Q_PROPERTY(bool galleryMode READ getGalleryMode WRITE setGalleryMode NOTIFY galleryModeChanged)
    Q_PROPERTY(bool displayThumbnails READ getDisplayThumbnails WRITE setDisplayThumbnails NOTIFY displayThumbnailsChanged)
    Q_PROPERTY(bool cacheThumbnails READ getCacheThumbnails WRITE setCacheThumbnails NOTIFY cacheThumbnailsChanged)

    // File ordering
    Q_PROPERTY(QString sortBy READ getSortBy WRITE setSortBy NOTIFY sortByChanged)
    Q_PROPERTY(QString sortOrder READ getSortOrder WRITE setSortOrder NOTIFY sortOrderChanged)
    Q_PROPERTY(QString dirOrder READ getDirOrder WRITE setDirOrder NOTIFY dirOrderChanged)

    // File display
    Q_PROPERTY(float fileOverlayPeriod READ getFileOverlayPeriod WRITE setFileOverlayPeriod NOTIFY fileOverlayPeriodChanged)
    Q_PROPERTY(bool browseAllFileTypes READ getBrowseAllFileTypes WRITE setBrowseAllFileTypes NOTIFY browseAllFileTypesChanged)
public:
    explicit Settings(QObject *parent = 0);

    QSettings *settings;

    // dirPath
    void setDirPath(const QString &dirPath);
    QString getDirPath() const;

    Q_INVOKABLE void cdUp();

    // defaultViewMode
    void setDefaultViewMode(const QString &defaultViewMode);
    QString getDefaultViewMode() const;

    // showHiddenFiles
    void setShowHiddenFiles(const bool &showHiddenFiles);
    bool getShowHiddenFiles() const;

    // showDirHeader
    void setShowDirHeader(const bool &showDirHeader);
    bool getShowDirHeader() const;

    // galleryMode
    void setGalleryMode(const bool &galleryMode);
    bool getGalleryMode() const;

    // displayThumbnails
    void setDisplayThumbnails(const bool &displayThumbnails);
    bool getDisplayThumbnails() const;

    // cacheThumbnails
    void setCacheThumbnails(const bool &cacheThumbnails);
    bool getCacheThumbnails() const;

    // sortBy
    void setSortBy(const QString &sortBy);
    QString getSortBy() const;

    // sortOrder
    void setSortOrder(const QString &sortOrder);
    QString getSortOrder() const;

    // dirOrder
    void setDirOrder(const QString &dirOrder);
    QString getDirOrder() const;

    // fileOverlayPeriod
    void setFileOverlayPeriod(const float &fileOverlayPeriod);
    float getFileOverlayPeriod() const;

    // browseAllFileTypes
    void setBrowseAllFileTypes(const bool &browseAllFileTypes);
    bool getBrowseAllFileTypes() const;

private:
    QString m_dirPath;
    QString m_defaultViewMode;
    bool m_galleryMode;

    bool m_showHiddenFiles;
    bool m_showDirHeader;
    bool m_displayThumbnails;
    bool m_cacheThumbnails;

    QString m_sortBy;
    QString m_sortOrder;
    QString m_dirOrder;

    float m_fileOverlayPeriod;
    bool m_browseAllFileTypes;

signals:
    void dirPathChanged(const QString &dirPath);
    void defaultViewModeChanged(const QString &defaultViewMode);
    void showHiddenFilesChanged(const bool &showHiddenFiles);
    void showDirHeaderChanged(const bool &showDirHeader);
    void galleryModeChanged(const bool &galleryMode);
    void displayThumbnailsChanged(const bool &displayThumbnails);
    void cacheThumbnailsChanged(const bool &cacheThumbnails);

    void directoryViewSettingsChanged();

    void sortByChanged(const QString &sortBy);
    void sortOrderChanged(const QString &sortOrder);
    void dirOrderChanged(const QString &dirOrder);

    void fileDisplaySettingsChanged();

    void fileOverlayPeriodChanged(const float &fileOverlayPeriod);
    void browseAllFileTypesChanged(const bool &browseAllFileTypes);

public slots:

};

#endif // SETTINGS_H
