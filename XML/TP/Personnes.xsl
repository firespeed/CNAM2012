<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">

<xsl:template match="scientifiques">
<html>
	<head>
		<title>Scientifiques celebres</title>
	</head>
	<body>
		<ul>
			<xsl:apply-templates select="personne" mode="toc"/>
		</ul>
			<xsl:apply-templates select="personne"/>
	</body>
</html>
</xsl:template>

<!-- Mode de la table des matières -->
<xsl:template match="personne" mode="toc">
		<xsl:apply-templates select="nom" mode="toc" />
</xsl:template>

<xsl:template match="nom" mode="toc">
	<li>
		<xsl:value-of select="nom_famille" />
		<xsl:value-of select="prenom" />		
	</li>
</xsl:template>

<!-- Mode normal d'affichage -->
<xsl:template match="personne">
	<p><xsl:apply-templates/></p>
</xsl:template>

</xsl:stylesheet>