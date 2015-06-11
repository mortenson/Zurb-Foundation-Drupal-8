========================================
ZURB FOUNDATION 4 - PRE DRUPAL 8 RELEASE
========================================

Getting Started
---------------

At the time of this writing, Twig is integrated into Drupal 8 core but a lot of theme function / render function cleanup remains. We are working diligently to keep up with the changes
as Drupal 8 development progresses towards a release.

Foundation Docs
---------------

Examples of Foundation markup can be found here: http://foundation.zurb.com/docs/

Dependencies
------------

Zurb Foundation theme dependencies are managed with a ruby Gemfile. This manages bundle dependencies and their versions for Foundation core and addons. When you run 'compass install foundation' against this
directory, the Gemfile is adhered to and Foundation is built accordingly.

The reason there is a Gemfile instead of a Composer file is because the Foundation project is built with Compass. This may change in the future to be more in line with Drupal 8 / Symfony way of managing dependencies.

The Gemfile.lock file is a generated result of installing from the Gemfile, recording each pacakge and version used to build the project.

Installing Ruby
---------------

Follow the guides at this URL for your applicable operating system:

  - http://www.ruby-lang.org/en/downloads/

There is a one click installer for Windows. If you're on OSX, we highly recommend using Homebrew to install Ruby.

You will also want to install RVM, a 'version manager' for Ruby - particularly if you are on OSX which ships with Ruby 1.8.x by default.

  - https://rvm.io/

Installing RubyGems
-------------------

RubyGems comes with RVM (above). If all went well during installation, you should be able to type this at the command line:

`gem list`

This should list the local gems currently installed. From here, you should be able to do the following:

`gem install zurb-foundation`
`gem install compass`

This will install the latest versions of Zurb Foundation gem and Compass gems required for building the Foundation core.

You can also specify gem versions with the command above. If the Gemfile in this theme changes and supports newer versions of the Zurb Foundation gem, you can install and target that specific release with:

`gem install zurb-foundation -v x.x.x`

Where x.x.x is the version number you want to install.

Installing this theme
---------------------

TBD

How to Use Zurb Foundation
--------------------------

TBD


