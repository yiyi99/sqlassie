// Copyright (C) 2008  Davis E. King (davis@dlib.net), Nils Labugt
// License: Boost Software License   See LICENSE.txt for the full license.
#undef DLIB_PNG_IMPORT_ABSTRACT
#ifdef DLIB_PNG_IMPORT_ABSTRACT

#include "image_loader_abstract.h"
#include "../algs.h"
#include "../pixel.h"
#include "../dir_nav.h"

namespace dlib
{

    class png_loader : noncopyable
    {
        /*!
            INITIAL VALUE
                Defined by the constructors

            WHAT THIS OBJECT REPRESENTS
                This object represents a class capable of loading PNG image files.
                Once an instance of it is created to contain a PNG file from
                disk you can obtain the image stored in it via get_image().
        !*/

    public:

        png_loader( 
            const char* filename 
        );
        /*!
            ensures
                - loads the PNG file with the given file name into this object
            throws
                - std::bad_alloc
                - image_load_error
                  This exception is thrown if there is some error that prevents
                  us from loading the given PNG file.
        !*/

        png_loader( 
            const std::string& filename 
        );
        /*!
            ensures
                - loads the PNG file with the given file name into this object
            throws
                - std::bad_alloc
                - image_load_error
                  This exception is thrown if there is some error that prevents
                  us from loading the given PNG file.
        !*/

        png_loader( 
            const dlib::file& f 
        );
        /*!
            ensures
                - loads the PNG file with the given file name into this object
            throws
                - std::bad_alloc
                - image_load_error
                  This exception is thrown if there is some error that prevents
                  us from loading the given PNG file.
        !*/

        ~png_loader(
        );
        /*!
            ensures
                - all resources associated with *this has been released
        !*/

        bool is_gray(
        ) const;
        /*!
            ensures
                - if (this object contains a grayscale image) then
                    - returns true
                - else
                    - returns false
        !*/
        
        bool is_rgb(
        ) const;
        /*!
            ensures
                - if (this object contains a 3 channel RGB image) then
                    - returns true
                - else
                    - returns false
        !*/

        bool is_rgba(
        ) const;
        /*!
            ensures
                - if (this object contains a 4 channel RGB alpha image) then
                    - returns true
                - else
                    - returns false
        !*/

        template<
            typename image_type 
            >
        void get_image( 
            image_type& img
        ) const;
        /*!
            requires
                - image_type == is an implementation of array2d/array2d_kernel_abstract.h
                - pixel_traits<typename image_type::type> is defined  
            ensures
                - loads the PNG image stored in this object into img
        !*/

    };
}

#endif // DLIB_PNG_IMPORT_ABSTRACT


