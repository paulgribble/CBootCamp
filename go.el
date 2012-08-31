(require 'org-publish)
(setq org-publish-project-alist
      '(
	("CBootCamp"
	 :base-directory "~/Desktop/CBootCamp/org/"
	 :base-extension "org"
	 :publishing-directory "~/Desktop/CBootCamp/html"
	 :publishing-function org-publish-org-to-html
	 :recursive t
	 :section-numbers nil
	 :html-postamble "<hr />%a | %d<br>This <span xmlns:dct=\"http://purl.org/dc/terms/\" href=\"http://purl.org/dc/dcmitype/Text\" rel=\"dct:type\">work</span> is licensed under a <a rel=\"license\" href=\"http://creativecommons.org/licenses/by-nc-sa/3.0/\">Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License</a><br><a rel=\"license\" href=\"http://creativecommons.org/licenses/by-nc-sa/3.0/\"><img alt=\"Creative Commons License\" style=\"border-width:0\" src=\"http://i.creativecommons.org/l/by-nc-sa/3.0/80x15.png\" /></a><br />"
	 :language en
	 :link-home "index.html"
	 :link-up "index.html"
	 :style "<link rel=\"stylesheet\" type=\"text/css\" href=\"mystyle.css\" />"
	 )
	("CBootCamp_html"
	 :base-directory "~/Desktop/CBootCamp/html/"
	 :base-extension "css\\|html"
	 :publishing-directory "/ssh:admin@leviathan.ssc.uwo.ca:~/gribblelab.org/CBootCamp/"
	 :publishing-function org-publish-attachment
	 :recursive t
	 )
	("CBootCamp_code"
	 :base-directory "~/Desktop/CBootCamp/code/"
	 :base-extension "c\\|h\\|txt\\|csv"
	 :publishing-directory "/ssh:admin@leviathan.ssc.uwo.ca:~/gribblelab.org/CBootCamp/code/"
	 :publishing-function org-publish-attachment
	 :recursive t
	 )
	("org" :components ("CBootCamp" "CBootCamp_html" "CBootCamp_code"))))

(org-publish-project "CBootCamp")
(org-publish-project "CBootCamp_html")
(org-publish-project "CBootCamp_code")
