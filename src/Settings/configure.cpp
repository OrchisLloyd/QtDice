#include "../headers/configure.h"

Configure::Configure( QWidget *parent )
    : QDialog( parent ),
      buttonBox( new QDialogButtonBox( QDialogButtonBox::Save
                                       | QDialogButtonBox::Cancel
                                       | QDialogButtonBox::Apply
                                       | QDialogButtonBox::Help ) ),
      labelIcon( new QLabel ),
      gridGroupBox( new QGroupBox( tr( "General Settings" ) ) ),
      gridGroupBox_Icon( new QGroupBox ),
      gridLayout( new QGridLayout ),
      grid_GeneralSettings( new QGridLayout ),
      gridButtons( new QGridLayout ),
      gridLabel( new QGridLayout ),
      pixmapSettings( new QPixmap( ":/resources/images/SettingsL.png" ) ),
      settings( new QSettings( "QtDice" ) ),
      soundCheckBox( new QCheckBox( "Play rolling sound?" ) )
{
    //Make this window modal
    setModal( true );
    setWindowTitle( tr( "QtDice Settings" ) );
    readSettings();

    connect( buttonBox.data(), &QDialogButtonBox::rejected, this, &Configure::reject );
    connect( buttonBox.data(), &QDialogButtonBox::accepted, this, &Configure::accept );
    connect( buttonBox.data(), &QDialogButtonBox::accepted, this, &Configure::writeSettings );

    connect( soundCheckBox.data(), &QCheckBox::clicked, this, &Configure::isCheckBoxUnsaved );

    gridLayout->addWidget( createGroupBox_Icon(), 0, 0 );
    gridLayout->addWidget( createGroupBox_General(), 0, 1 );

    gridButtons->addWidget( buttonBox.data(), 0, 0 );
    gridLayout->addLayout( gridButtons.data(), 1, 1 );

// Disable sound-related widgets if the user doesn't need them
#ifndef ENABLE_SOUND
    soundCheckBox->setChecked( false );
    gridGroupBox->setEnabled( false );
#endif

    setMinimumSize( 470, 250 );
    setLayout( gridLayout.data() );
}

Configure::~Configure()
{
    qDebug() << "Deleting configure UI";
}

void Configure::show()
{
    QDialog::show();
}

QGroupBox *Configure::createGroupBox_General()
{
    grid_GeneralSettings->addWidget( soundCheckBox.data(), 0, 0 );
    gridGroupBox->setLayout( grid_GeneralSettings.data() );
    return gridGroupBox.data();
}

QGroupBox *Configure::createGroupBox_Icon()
{
    labelIcon->setPixmap( *pixmapSettings.data() );
    labelIcon->setScaledContents( true );
    labelIcon->setMaximumSize( 100, 100 );
    Q_ASSERT_X( labelIcon->pixmap() != 0, "labelIcon error", "Fault" );

    gridLabel->addWidget( labelIcon.data(), 0, 0 );
    gridGroupBox_Icon->setLayout( gridLabel.data() );

    return gridGroupBox_Icon.data();
}

void Configure::readSettings()
{
    settings->beginGroup( tr( "/sound" ) );
    settings->sync();
    soundCheckBox->setChecked( settings->value( "rolling_sound" ).toInt() );
    settings->endGroup();
}

void Configure::writeSettings()
{
    settings->beginGroup( tr( "/sound" ) );
    settings->setValue( tr( "rolling_sound" ), soundCheckBox->checkState() );
    settings->sync();
    settings->endGroup();
}

void Configure::closeEvent( QCloseEvent *closeEv )
{
    if ( isCheckBoxUnsaved() )
    {
        int r = QMessageBox::warning( this,
                                      tr( "Unsaved Changes" ),
                                      tr( "Do you want to save the changes?" ),
                                      QMessageBox::Save |
                                      QMessageBox::Discard |
                                      QMessageBox::Cancel );

        if ( r == QMessageBox::Save )
        {
            writeSettings();
            closeEv->accept();
        }
        else if ( r == QMessageBox::Discard ) {
            closeEv->accept();
        }
        else {
            closeEv->ignore();
        }
    }
}

bool Configure::isCheckBoxUnsaved()
{
    readSettings();
    if ( settings->value( "rolling_sound" ).toBool() != soundCheckBox->isChecked() )
    {
        emit soundCheckUnsaved();
        b_isSoundBoxUnSaved = true;
        return true;
    }
    return false;
}

#include "headers/moc_configure.cpp"
// kate: indent-mode cstyle; replace-tabs on; 
