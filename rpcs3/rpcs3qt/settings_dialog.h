#pragma once

#include "gui_settings.h"
#include "emu_settings.h"

#include "Emu/GameInfo.h"

#include <QDialog>
#include <QTabWidget>

#include <memory>

namespace Ui {
	class settings_dialog;
}

class settings_dialog : public QDialog
{
	Q_OBJECT

public:
	explicit settings_dialog(std::shared_ptr<gui_settings> xSettings, Render_Creator r_Creator, QWidget *parent = 0, GameInfo *game = nullptr);
	void SetActiveTab(int index);
	private Q_SLOTS:
	void OnBackupCurrentConfig();
	void OnApplyConfig();
	void OnApplyStylesheet();
Q_SIGNALS:
	void GuiSettingsSyncRequest();
	void GuiStylesheetRequest(const QString& path);
	void GuiSettingsSaveRequest();
private:
	//emulator tab
	void AddConfigs();
	void AddStylesheets();
	QString m_startingStylesheet;
	QString m_startingConfig;
	//gpu tab
	QString m_oldRender = "";
	bool m_isD3D12 = false;
	bool m_isVulkan = false;

	Ui::settings_dialog *ui;
	std::shared_ptr<gui_settings> xgui_settings;
};
