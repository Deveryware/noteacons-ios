Pod::Spec.new do |s|
  s.name             = "NoteaconsSDK"
  s.version          = "1.1.0"
  s.summary          = "Simple, effective and potent proximity campaigns."
  s.description      = <<-DESC
                       Enjoy the Noteacons experience. Send messages to your users at the right time, in the right place.
                       DESC
  s.homepage         = "https://github.com/Deveryware/noteacons-ios"
  s.license          = { :type => "BSD", :file => "LICENSE" }
  s.author           = { "Deveryware Iberia" => "info@noteacons.com" }
  s.source           = { :git => "https://github.com/Deveryware/noteacons-ios.git", :tag => "v1.1.0"  }
  s.social_media_url = 'https://twitter.com/noteacons'

  s.platform     = :ios, '8.0'
  s.requires_arc = true

  s.vendored_frameworks = "NoteaconsSDK.framework"
end
