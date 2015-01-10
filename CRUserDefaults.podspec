#
# Be sure to run `pod lib lint CRUserDefaults.podspec' to ensure this is a
# valid spec and remove all comments before submitting the spec.
#
# Any lines starting with a # are optional, but encouraged
#
# To learn more about a Podspec see http://guides.cocoapods.org/syntax/podspec.html
#

Pod::Spec.new do |s|
  s.name             = "CRUserDefaults"
  s.version          = "0.1.1"
  s.summary          = "CRUserDefaults is a helper singleton class that helps writing information in NSUserDefaults as object."
  s.description      = <<-DESC
CRUserDefaults is a helper singleton class that helps writing information in NSUserDefaults as object.


                       * Markdown format.
                       * Don't worry about the indent, we strip it!
                       DESC
  s.homepage         = "https://github.com/riosc/CRUserDefaults"
  # s.screenshots     = "www.example.com/screenshots_1", "www.example.com/screenshots_2"
  s.license          = 'MIT'
  s.author           = { "Carlos Rios" => "rioscarlosd@gmail.com" }
  s.source           = { :git => "https://github.com/riosc/CRUserDefaults.git", :tag => s.version.to_s }
  # s.social_media_url = 'https://twitter.com/cadamel'

  s.platform     = :ios, '7.0'
  s.requires_arc = true

  s.source_files = 'Pod/Classes'
  s.resource_bundles = {
    'CRUserDefaults' => ['Pod/Assets/*.png']
  }

  # s.public_header_files = 'Pod/Classes/**/*.h'
  # s.frameworks = 'UIKit', 'MapKit'
  # s.dependency 'AFNetworking', '~> 2.3'
end
