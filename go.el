(require 'ox-publish)
(setq org-export-with-sub-superscripts nil)
(setq org-publish-project-alist
      '(
	("CBootCamp"
	 :base-directory "org/"
	 :base-extension "org"
	 :publishing-directory "~/Documents/github/CBootCamp/html"
	 :publishing-function org-html-publish-to-html
	 :recursive t
	 :htmlized-source t
	 :section-numbers nil
	 :html-postamble "<hr />%a | %d<br><a rel="license" href="http://creativecommons.org/licenses/by/4.0/"><img alt="Creative Commons License" style="border-width:0" src="https://i.creativecommons.org/l/by/4.0/80x15.png" /></a><br />This work is licensed under a <a rel="license" href="http://creativecommons.org/licenses/by/4.0/">Creative Commons Attribution 4.0 International License</a>.<br />"
	 :language en
	 :html-link-home "index.html"
	 :html-link-up "index.html"
	 :html-head "<link rel=\"stylesheet\" type=\"text/css\" href=\"mystyle.css\" /><script>(function(i,s,o,g,r,a,m){i['GoogleAnalyticsObject']=r;i[r]=i[r]||function(){(i[r].q=i[r].q||[]).push(arguments)},i[r].l=1*new Date();a=s.createElement(o),m=s.getElementsByTagName(o)[0];a.async=1;a.src=g;m.parentNode.insertBefore(a,m)})(window,document,'script','//www.google-analytics.com/analytics.js','ga');ga('create', 'UA-52544521-1', 'auto');ga('send', 'pageview');</script>"
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
