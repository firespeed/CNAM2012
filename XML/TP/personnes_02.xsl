<?xml version="1.0" encoding="ISO-8859-1"?>
<xsl:stylesheet version="1.0"
xmlns:xsl="http://www.w3.org/1999/XSL/Transform">

<xsl:template match="/">
  <dl>
    <xsl:apply-templates select="descendant::personne"/>
  </dl>
</xsl:template>

<xsl:template match="personne">
  <dt><xsl:value-of select="child::nom"/></dt>
  <dd>
		<ul>
			<xsl:apply-templates select="child::nom/following-sibling::*"/>
		</ul>
  </dd>
</xsl:template>

<xsl:template match="*">
	  <li><xsl:value-of select="self::*"/></li>
</xsl:template>

</xsl:stylesheet>
