(require 'org-publish)
(setq org-publish-project-alist
      '(
	("CBootCamp"
	 :base-directory "org/"
	 :base-extension "org"
	 :publishing-directory "html"
	 :publishing-function org-publish-org-to-html
	 :recursive t
	 :htmlized-source t
	 :section-numbers nil
	 :html-postamble "<hr />%a | %d<br><b>support this project with bitcoin</b>:1FTSaJh7JbqArgGhMMWz1yiUWsoCrM8nsQ<br>This <span xmlns:dct=\"http://purl.org/dc/terms/\" href=\"http://purl.org/dc/dcmitype/Text\" rel=\"dct:type\">work</span> is licensed under a <a rel=\"license\" href=\"http://creativecommons.org/licenses/by-nc-sa/3.0/\">Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License</a><br><a rel=\"license\" href=\"http://creativecommons.org/licenses/by-nc-sa/3.0/\"><img alt=\"Creative Commons License\" style=\"border-width:0\" src=\"http://i.creativecommons.org/l/by-nc-sa/3.0/80x15.png\" /></a><br />"
	 :language en
	 :link-home "index.html"
	 :link-up "index.html"
	 :style "<link rel=\"stylesheet\" type=\"text/css\" href=\"mystyle.css\" /><script>(function(i,s,o,g,r,a,m){i['GoogleAnalyticsObject']=r;i[r]=i[r]||function(){(i[r].q=i[r].q||[]).push(arguments)},i[r].l=1*new Date();a=s.createElement(o),m=s.getElementsByTagName(o)[0];a.async=1;a.src=g;m.parentNode.insertBefore(a,m)})(window,document,'script','//www.google-analytics.com/analytics.js','ga');ga('create', 'UA-52544521-1', 'auto');ga('send', 'pageview');</script>"
	 )
	("CBootCamp_html"
	 :base-directory "html/"
	 :base-extension "css\\|html"
	 :publishing-directory "/ssh:plg@toro.ssc.uwo.ca:~/gribblelab.org/CBootCamp/"
	 :publishing-function org-publish-attachment
	 :recursive t
	 )
	("CBootCamp_code"
	 :base-directory "code/"
	 :base-extension "c\\|h\\|txt\\|csv"
	 :publishing-directory "/ssh:plg@toro.ssc.uwo.ca:~/gribblelab.org/CBootCamp/code/"
	 :publishing-function org-publish-attachment
	 :recursive t
	 )
	("org" :components ("CBootCamp" "CBootCamp_html" "CBootCamp_code"))))

(org-publish-project "CBootCamp")
(org-publish-project "CBootCamp_html")
(org-publish-project "CBootCamp_code")
