#ifndef DELEGATE_PROFIL_SUPPRIMER_H
#define DELEGATE_PROFIL_SUPPRIMER_H
#include <QItemDelegate>
class DelegateProfilSupprimer : public QItemDelegate
{
public:
	QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option,
		const QModelIndex &index) const;

	void setEditorData(QWidget *editor, const QModelIndex &index) const;
	void setModelData(QWidget *editor, QAbstractItemModel *model,
		const QModelIndex &index) const;

	void updateEditorGeometry(QWidget *editor,
		const QStyleOptionViewItem &option, const QModelIndex &index) const;
};

#endif // DELEGATE_PROFIL_SUPPRIMER_H
