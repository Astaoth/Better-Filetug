# 
# Do NOT Edit the Auto-generated Part!
# Generated by: spectacle version 0.27
# 

Name:       harbour-filetug

# >> macros
# << macros

%{!?qtc_qmake:%define qtc_qmake %qmake}
%{!?qtc_qmake5:%define qtc_qmake5 %qmake5}
%{!?qtc_make:%define qtc_make make}
%{?qtc_builddir:%define _builddir %qtc_builddir}
Summary:    harbour-filetug
Version:    0.1
Release:    9
Group:      Qt/Qt
License:    Unlicense <http://unlicense.org/>
URL:        http://example.org/
Source0:    %{name}-%{version}.tar.bz2
Source100:  harbour-filetug.yaml
Requires:   qt5-qtsvg-plugin-imageformat-svg >= 0-1.2.2
Requires:   sailfishsilica-qt5 >= 0.10.9
BuildRequires:  pkgconfig(sailfishapp) >= 0.0.10
BuildRequires:  pkgconfig(Qt5Core)
BuildRequires:  pkgconfig(Qt5Qml)
BuildRequires:  pkgconfig(Qt5Quick)
BuildRequires:  desktop-file-utils

%description
A feature filled file manager application for SailfishOS

%prep
%setup -q -n %{name}-%{version}

# >> setup
# << setup

%build
# >> build pre
# << build pre

%qtc_qmake5 

%qtc_make %{?_smp_mflags}

# >> build post
# << build post

%install
rm -rf %{buildroot}
# >> install pre
# << install pre
%qmake5_install

# >> install post
# << install post

desktop-file-install --delete-original       \
  --dir %{buildroot}%{_datadir}/applications             \
   %{buildroot}%{_datadir}/applications/*.desktop

%files
%defattr(-,root,root,-)
/usr/share/harbour-filetug
/usr/share/icons/hicolor/86x86/apps
/usr/share/applications
/usr/share/harbour-filetug
/usr/bin
%{_datadir}/icons/hicolor/86x86/apps/%{name}.png
%{_datadir}/applications/%{name}.desktop
%{_datadir}/%{name}/qml
%{_bindir}
/usr/share/harbour-filetug
# >> files
# << files
