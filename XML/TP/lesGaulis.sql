SELECT NOM, ADRESSE, IMAGE, NOM_SPECIALITE, NOM_BATAILLE, QTE, NOM_CASQUE  
FROM villageois, prise_casque, bataille, specialite , casque 
WHERE 
prise_casque.ID_VILLAGEOIS = VILLAGEOIS.ID_VILLAGEOIS 
AND prise_casque.ID_BATAILLE = bataille.ID_BATAILLE 
AND specialite.ID_SPECIALITE = villageois.ID_SPECIALITE
AND prise_casque.ID_CASQUE = casque.ID_CASQUE 
ORDER BY NOM
 