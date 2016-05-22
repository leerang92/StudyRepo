#include "Attack.h"
#include "LongAttack.h"
#include "ShortAttack.h"
#include "BowAttack.h"
#include "SwordAttack.h"
#include "AttackType.h"

void main()
{
	CAttack *att = new CAttackType();
	CLongAttack *bowAtt = new CBowAttack();
	CShortAttack *swordAtt = new CSwordAttack();

	CLongAttack *longAttack = bowAtt;
	CShortAttack *shortAttack = swordAtt;

	att->setLongAttack(longAttack);
	att->setShotAttack(swordAtt);

	if (!att->CheckRange(4)) {
		att->ShowShotAttack();
	}
	else
		att->ShowLongAttack();

	

	
}