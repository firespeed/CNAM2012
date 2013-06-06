<?xml version="1.0" encoding="ISO-8859-1"?> 
<xsl:stylesheet version = '1.0' 
	xmlns:xsl='http://www.w3.org/1999/XSL/Transform'>

<!-- D�finition de l'ent�te correpondant � l'�l�ment racine -->
<xsl:template match="/">
	<html>
		<head>
		Au coeur du langage XSLT
			<title><xsl:value-of select="/Concert/Ent�te"/></title>
		</head>
		<body bgcolor="white" text="black">
			<xsl:apply-templates/>
		</body>
	</html>
</xsl:template>

<!-- D�finition des templates -->
<xsl:template match="/bibliographoi/livre[1]">
	<p> <xsl:value-of select="."/> Titre</p>
</xsl:template>


</xsl:stylesheet>