using entities.Concrete;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Bll.Abstract
{
    public interface ICezalarBll
    {
        List<cezalar> getAll();
        cezalar getOneById(int id);
        void Update(cezalar cezalar);
        void Add(cezalar cezalar);
        void Delete(cezalar cezalar);
    }
}
