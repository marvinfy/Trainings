#include "radiobuttongroup.h"
#include <QRadioButton>

RadioButtonGroup::RadioButtonGroup(QWidget * parent)
	: QGroupBox(parent)
{
	m_rbGroup = new QButtonGroup(this);
	m_rbGroup->setExclusive(true); // só um pode estar marcado
}

// Não é possivel inserir os 'RadioButtons" no "ButtonGroup" já na construtora,
// pois quando ela é chamada o "GroupBox" ainda está vazio (os "RadioButtons" devem ter sido acrescentados após sua criação)
// Então a função abaixo deverá ser chamada na construtora do Widget que estiver usando o GroupBox
// para que o "QButtonGroup" adicione todos os "RadioButtons" já inseridos no GroupBox
void RadioButtonGroup::groupRadioButtons()
{
	// percorre a lista de "childs" do GroupBox:
	foreach ( QObject * obj, children())
	{
		QRadioButton * rb = qobject_cast<QRadioButton*>(obj);
		// se não está nulo (então é um 'QRadioButton'!)
		if ( rb )
			m_rbGroup->addButton( rb );
	}
}

// desmarca todos:
void RadioButtonGroup::uncheckAll ()
{
	m_rbGroup->setExclusive(false);

	foreach ( QAbstractButton * btn , m_rbGroup->buttons() )
		btn->setChecked(false);

	m_rbGroup->setExclusive(true);
}

// marca o 'RadioButton' que contiver o texto especificado:
void RadioButtonGroup::checkButton(const QString & textToCheck)
{
	m_rbGroup->setExclusive(false);

	foreach ( QAbstractButton * btn , m_rbGroup->buttons() )
		btn->setChecked( btn->text()==textToCheck );

	m_rbGroup->setExclusive(true);
}


